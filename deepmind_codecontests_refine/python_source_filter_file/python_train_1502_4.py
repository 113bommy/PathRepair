a = input()
b, s, c = list(map(int, input().split()))
rb, rs, rc = list(map(int, input().split()))
total = int(input())
ns = 0
nb = 0
nc = 0
for i in a:
    if i == 'B':
        nb += 1
    if i == "S":
        ns += 1
    if i == "C":
        nc += 1
def get(x):
    f=max(0,nb*x-b)*rb+max(0,ns*x-s)*rs+max(0,nc*x-c)*rc
    # print(x,f)
    return f

start=0
end=1000000000000
maximum=0
while start<=end:

    mid=(start+end)//2
    if get(mid)<=total:
        start=mid+1
        maximum=max(mid,maximum)
    else:
        end=mid-1

print(maximum)