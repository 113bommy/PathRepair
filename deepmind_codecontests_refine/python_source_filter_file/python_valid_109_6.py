def printOperations(num,n):
    list1=[]
    list1[:0]=num
    for i in range(n):
        list1[i] = int(list1[i])
    count = list1[n-1]
    for i in range(n-1):
        if list1[i]!=0:
            count+=list1[i]+1
        print(count)
 
 
def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        num = input()
        printOperations(num,n)
 
 
if __name__ == "__main__":
    main()