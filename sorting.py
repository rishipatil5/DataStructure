def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def get_top_five_salaries(arr):
    print("Top five salaries are:")
    top_five = arr[-1:-6:-1]
    for salary in top_five:
        print(salary)

def main():
    ch = int(input("Enter 1 for Bubble Sort, 2 for Selection Sort: "))
    n = int(input("Enter number of employees:\n "))
    num_employees = []

    print("Enter the salaries of employees:")
    for i in range(n):
        salary = float(input())
        num_employees.append(salary)

    print("Original salaries list:", num_employees)

    if ch == 1:
        bubble_sort(num_employees)
        print("Salaries after Bubble Sort:", num_employees)
    elif ch == 2:
        selection_sort(num_employees)
        print("Salaries after Selection Sort:", num_employees)
    else:
        print("Invalid choice")
        return        
    
    get_top_five_salaries(num_employees)

if __name__ == "__main__":
    main()