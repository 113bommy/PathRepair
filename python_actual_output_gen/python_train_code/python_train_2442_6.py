S=input()
Q=int(input())
head=""
tail=""
rev=False

for _ in range(Q):
    q = input().split()
    if len(q)==1:
        rev != rev
    else:
        if rev ^ (q[1]=="1"):
            head+=q[2]
        else:
            tail+=q[2]
if rev:
    print(tail[::-1]+S[::-1]+head)
else:
    print(head[::-1]+S+tail)
