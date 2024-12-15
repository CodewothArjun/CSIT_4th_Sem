import numpy as np

# Parameters
population_size = 10
genome_length = 10
mutation_rate = 0.01
n_generations = 100

# Create initial population
def create_population(size, length):
    return np.random.randint(2, size=(size, length))

# Fitness function: count the number of 1's
def fitness(genome):
    return np.sum(genome)

# Selection function: select parents based on fitness
def select_parents(population, fitness_scores):
    probabilities = fitness_scores / np.sum(fitness_scores)
    parents_indices = np.random.choice(range(population_size), size=2, p=probabilities)
    return population[parents_indices]

# Crossover function: create offspring from parents
def crossover(parent1, parent2):
    point = np.random.randint(1, genome_length-1)
    offspring1 = np.concatenate((parent1[:point], parent2[point:]))
    offspring2 = np.concatenate((parent2[:point], parent1[point:]))
    return offspring1, offspring2

# Mutation function: flip bits in genome
def mutate(genome, rate):
    for i in range(len(genome)):
        if np.random.rand() < rate:
            genome[i] = 1 - genome[i]

# Main genetic algorithm function
def genetic_algorithm():
    population = create_population(population_size, genome_length)
    for generation in range(n_generations):
        fitness_scores = np.array([fitness(genome) for genome in population])
        parents = select_parents(population, fitness_scores)
        offspring1, offspring2 = crossover(parents[0], parents[1])
        mutate(offspring1, mutation_rate)
        mutate(offspring2, mutation_rate)
        
        # Replace the worst two individuals with the new offspring
        worst_indices = np.argsort(fitness_scores)[:2]
        population[worst_indices[0]] = offspring1
        population[worst_indices[1]] = offspring2
        
        # Print summary every 10 generations
        if generation % 10 == 0:
            best_fitness = np.max(fitness_scores)
            best_individual = population[np.argmax(fitness_scores)]
            print(f"Generation {generation}: Best Fitness = {best_fitness}")

    # Print final result
    final_fitness_scores = np.array([fitness(genome) for genome in population])
    best_fitness = np.max(final_fitness_scores)
    best_individual = population[np.argmax(final_fitness_scores)]
    print(f"Final Best Individual: {best_individual}")
    print(f"Final Best Fitness: {best_fitness}")

# Run the genetic algorithm
genetic_algorithm()

print("\n\n")