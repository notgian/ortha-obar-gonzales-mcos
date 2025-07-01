import numpy as np

# generates input data for problem sizes 2^n for n=6 to 15

def generate_data_set():
    data_set = {}
    
    n = 6 

    while (n <=15):
        sample_set = list()
        ub = n * 10
        lb = n * 10 * -1
        problem_size = 2**n  

        np.set_printoptions(precision=1)
        random_data_x = np.random.uniform(lb, ub, problem_size)
        random_data_y = np.random.uniform(lb, ub, problem_size)

        for i in range(problem_size):
            sample_set.append( (round(random_data_x[i], 6), round(random_data_y[i], 6)) )
        
        data_set[n] = sample_set 
        n+=1
    
    return data_set
    
def main():
    data_set = generate_data_set()

    for key in data_set.keys():
        sample_list = data_set[key]
        print("sample: ", sample_list)
        problem_size = len(sample_list)

        string_buffer = f"{problem_size}\n"
        
        for item in sample_list:
            string_buffer += "{:<10f} {:<10f}\n".format(item[0], item[1])

        # print(string_buffer)

        with open(f"n{problem_size}.txt", "w") as f:
            f.write(string_buffer)

if __name__ == "__main__":
    main()