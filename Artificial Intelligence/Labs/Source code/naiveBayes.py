import numpy as np

class NaiveBayes:
    def __init__(self):
        self.class_probs = {}
        self.feature_probs = {}
        self.classes = []
        self.feature_count = 0

    def fit(self, X, y):
        """
        Fit the Naive Bayes model using training data.
        
        :param X: 2D numpy array of shape (n_samples, n_features) representing the feature matrix
        :param y: 1D numpy array of shape (n_samples,) representing the class labels
        """
        self.classes = np.unique(y)
        self.feature_count = X.shape[1]

        # Calculate prior probabilities
        self.class_probs = {c: np.mean(y == c) for c in self.classes}

        # Calculate likelihoods
        self.feature_probs = {}
        for c in self.classes:
            X_c = X[y == c]
            # Use Laplace smoothing
            class_feature_probs = (np.sum(X_c, axis=0) + 1) / (X_c.shape[0] + 2)
            self.feature_probs[c] = class_feature_probs

    def predict(self, X):
        """
        Predict the class labels for the provided data.
        
        :param X: 2D numpy array of shape (n_samples, n_features) representing the feature matrix
        :return: 1D numpy array of shape (n_samples,) representing the predicted class labels
        """
        predictions = []
        for x in X:
            class_probs = {}
            for c in self.classes:
                # Calculate log-probabilities to avoid numerical issues with small numbers
                log_prob = np.log(self.class_probs[c])
                log_prob += np.sum(x * np.log(self.feature_probs[c]) + (1 - x) * np.log(1 - self.feature_probs[c]))
                class_probs[c] = log_prob
            # Predict the class with the highest probability
            predicted_class = max(class_probs, key=class_probs.get)
            predictions.append(predicted_class)
        return np.array(predictions)

# Example usage
if __name__ == "__main__":
    # Sample data: 4 samples, 2 features
    X_train = np.array([
        [1, 0],
        [1, 1],
        [0, 1],
        [0, 0]
    ])
    y_train = np.array([1, 1, 0, 0])  # Binary classification
    
    # Create and train the Naive Bayes classifier
    nb = NaiveBayes()
    nb.fit(X_train, y_train)

    # Test data
    X_test = np.array([
        [1, 0],
        [0, 1]
    ])
    
    # Predict the class labels
    predictions = nb.predict(X_test)
    print("Predictions:", predictions)
print("\n\n")