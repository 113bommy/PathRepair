def calc(n,s):
    curr=0
    n1=str(n)
    for i in range(len(n1)):
        curr+=ord(n1[i])-ord('0')
    if curr<=s:
        return 0
    curr=0
    i=0
    while i<len(n1) and curr+int(n1[i])+1<=s:
        curr+=ord(n1[i])-ord('0')
        i+=1
    # print(i)
    return 10**(len(n1)-i)- int(n1[i:])

t=int(input())
for i in range(t):
    n,s=list(map(int,input().split()))
    print(calc(n,s))