n=int(input())
for i in range(n):
    a=input()
    l=len(a)
    str=""
    str=a[0:2]
    for i in range(3,l):
        str+=a[i]
    print(str)