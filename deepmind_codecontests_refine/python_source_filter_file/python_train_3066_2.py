n=int(input())
lst=[]
for i in range(n):
    n1=input().split()
    if(n1[0]+''+n1[1]) not in lst:
        lst.append(n1[0]+''+n1[1])
print(len(lst))
