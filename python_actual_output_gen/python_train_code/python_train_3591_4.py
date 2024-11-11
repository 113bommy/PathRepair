import sys
arr = list(map(int, input().split()))
k=arr[0]
a=arr[1]
b=arr[2]
s=input()
n=len(s)
p=n//k
r=n%k
ma=p
if(r!=0):
    ma+=1
if(ma<a or ma>b):
    print("No solution")
    sys.exit()
stt=0
end=ma
for i in range(r):
    print(s[stt:end])
    stt+=ma
    end+=ma
end=stt+p
for i in range(k-r):
    print(s[stt:end])
    stt+=p
    end+=p