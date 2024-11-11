n=int(input())
kw=input().split()
m=int(input())
bw=input().split()
a=[]
b=[]
for i in range(n):
    a.append(int(kw[i]))
for i in range(m):
    b.append(int(bw[i]))
a.sort()
b.sort()
count=0
# j=min(len(a),len(b))
# while j>=0 :
#     if abs(a[j]-b[j])>1 :
#         if len(a)>len(b);
#             a=a[:j]
#         else:
#
#         j = min(len(a), len(b))
#     else:
#         continue
if len(a)<=len(b):
    for k in range(len(a)):
        j=0
        while(j<len(b)):
            if abs(a[k]-b[j])<=1:
                count+=1
                b=b[j+1:]
                break
            elif a[k]>b[j]:

                b=b[j+1:]
                j=0
            else:
                break
else:
    for k in range(len(b)):
        j = 0
        while (j < len(a)):
            if abs(b[k] - a[j]) <= 1:
                count += 1
                a=a[j+1:]
                break
            elif b[k] > a[j] :

                a = a[j+1:]
                j=0
            else:
                break
print(count)








