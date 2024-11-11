ans=0
st = input()
n1 = len(st)
k = int(input())
n2 = n1+k
w = [int(x) for x in input().split()]
maxx = 0
i = 1
for x in w :
    if maxx < x :
        maxx = x
for x in st :
    ans = ans + i*w[ord(x)-ord('a')]
    i=i+1
ans = ans + maxx*((n2*(n2+1))-(n1*(n1+1)))/2

print(ans,end = "", sep = "")