import numpy as np

# Define activation functions and their derivatives
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

# Define the neural network class
class NeuralNetwork:
    def __init__(self, input_size, hidden_size, output_size):
        # Initialize weights
        self.input_size = input_size
        self.hidden_size = hidden_size
        self.output_size = output_size
        
        self.weights_input_hidden = np.random.rand(self.input_size, self.hidden_size)
        self.weights_hidden_output = np.random.rand(self.hidden_size, self.output_size)
        
        self.bias_hidden = np.random.rand(self.hidden_size)
        self.bias_output = np.random.rand(self.output_size)
    
    def forward(self, X):
        # Forward pass
        self.hidden_layer_input = np.dot(X, self.weights_input_hidden) + self.bias_hidden
        self.hidden_layer_output = sigmoid(self.hidden_layer_input)
        self.output_layer_input = np.dot(self.hidden_layer_output, self.weights_hidden_output) + self.bias_output
        self.output = sigmoid(self.output_layer_input)
        return self.output
    
    def backward(self, X, y, learning_rate):
        # Backward pass
        output_error = y - self.output
        output_delta = output_error * sigmoid_derivative(self.output)
        
        hidden_error = np.dot(output_delta, self.weights_hidden_output.T)
        hidden_delta = hidden_error * sigmoid_derivative(self.hidden_layer_output)
        
        # Update weights and biases
        self.weights_input_hidden += np.dot(X.T, hidden_delta) * learning_rate
        self.weights_hidden_output += np.dot(self.hidden_layer_output.T, output_delta) * learning_rate
        
        self.bias_hidden += np.sum(hidden_delta, axis=0) * learning_rate
        self.bias_output += np.sum(output_delta, axis=0) * learning_rate
    
    def train(self, X, y, epochs, learning_rate):
        for epoch in range(epochs):
            output = self.forward(X)
            self.backward(X, y, learning_rate)
            if (epoch + 1) % 1000 == 0:
                loss = np.mean(np.square(y - output))
                print(f'Epoch {epoch + 1}, Loss: {loss}')

# Example usage
if __name__ == "__main__":
    # Example data: XOR problem
    X_train = np.array([
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1]
    ])
    y_train = np.array([
        [0],
        [1],
        [1],
        [0]
    ])
    
    # Initialize and train the neural network
    input_size = 2
    hidden_size = 4
    output_size = 1
    
    nn = NeuralNetwork(input_size, hidden_size, output_size)
    nn.train(X_train, y_train, epochs=10000, learning_rate=0.1)
    
    # Test the neural network
    print("Predictions:")
    for x in X_train:
        print(f"Input: {x}, Prediction: {nn.forward(x)}")
print("\n\n")