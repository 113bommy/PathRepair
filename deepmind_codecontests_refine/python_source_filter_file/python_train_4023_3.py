inp=lambda:map(int,input().split())
n=int(input())

num=0
a=set()
b=set()
for i in range(26):
    a.add(chr(i+ord('a')))
    b.add(chr(i+ord('a')))

fl=0
cnt=0

for i in range(n):
    mark,word=input().split()
    word=set(word)

    if ((mark=='!' or mark=='?') and fl==1 and i!=n-1):
        cnt+=1

    if mark=='!':
        a=a.intersection(word)

    if mark=='.':
        a=a.difference(word)

    if mark=='?' and i!=n-1:
        a.discard(word)

    if fl==0 and len(a)==1: 
        fl=1

print(cnt)