a=input()
c=len(a)
if c%2==0:
    s=a[c//2-1]
    left=a[:c//2-1][::-1]
    right=a[c//2:]
else:
    s=a[c//2]
    left=a[:c//2][::-1]
    right=a[c//2+1:]
for i in range(c//2):
    if i < len(right):
        s+=right[i]
    if i < len(left):
        s+=left[i]
print(s)