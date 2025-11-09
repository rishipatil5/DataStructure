lib=list()
n=int(input("enter no. of members: "))
for i in range(n):
    books = int(input("enter books borrowed {i+1} :"))
    lib.append(books)
print(lib)

def average() :
    total=0
    for i in range(n):
        total+=lib[i]
    average = total/n
    print("average:",average)

def min_max():
    for i in range(n):
        min_index=0
        max_index=0
        for i in range(n):
            if (lib[i]!=0):
                min_index = i
                break
        for i in range(0,n):        
            if lib[i]<lib[min_index] and lib[i]!=0 :
                min_index=i
            if lib[i]>lib[max_index] :
                max_index=i
    print("lowest book borrowed",lib[min_index])
    print("highest book borrowed",lib [max_index])  

def zero_count():
    count = 0
    for i in range(n):
        if lib[i]==0:
            count+=1
    print("no. of members who did not borrow any book:",count)

def frequency():
    freq = 0
    for i in range(n):
        count = 0
        if lib[i] != 0:
            for j in range(n):
                if lib[i] == lib[j]:
                    count += 1
        if freq < count:
            freq = count
            element = lib[i]
    print(f"Highest frequency {freq} with borrow count of {element}")

def main():
    while True:
        print("Main Menu :")
        print("1.Average")
        print("2.Min and Max")
        print("3.Zero Count")
        print("4.Highest Frequency")
        print("5.Exit")
        s = int(input("Enter your choice(1-5): "))
        if s==1:
            average()
        elif s==2:
            min_max()
        elif s==3:
            zero_count()
        elif s==4:
            frequency()
        elif s==5:
            print("Exiting...")

            quit()
        else:
            continue

main()