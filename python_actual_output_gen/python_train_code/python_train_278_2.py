n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
res = 0
a = sorted(a)
b = sorted(b)
i , j = 0 , 0
while i<n and j<m:
        if abs(a[i]-b[j])<2:
                res+=1
                i+=1
                j+=1
        else:
                if a[i]<a[j]:
                        i+=1
                else:
                        j+=1
print(res)