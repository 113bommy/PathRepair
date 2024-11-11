# x=[int(q) for q in input().split()]
# y=[int(q) for q in input().split()]
# z=[int(q) for q in input().split()]
# z=sorted(z)
# count=0
# # sc=x[1]
# # i=0
# # for q in range(x[0]):
# #     for w in range(sc-i):
# #         if y[q]==z[w] or y[q]==z[w]-x[2] or y[q]==z[w]+x[2]:
# #             count+=1
# #             z.pop(w)
# #             i+=1
# #             break
# i=1
# for q in y:
#     s=0
#     e=x[1]-i
#     while s<=e:
#         mid=(s+e)//2
#         if (z[mid]==q or (z[mid]-x[2])==q or (z[mid]+x[2])==q):
#             count+=1
#             z.pop(mid)
#             i+=1
#             e-=1
#         elif q<z[mid]:
#             e=mid-1
#         else:
#             s=mid+1
# print(count)

x=int(input())
y=[int(q) for q in input().split()]
odd=0
even=0
for q in y:
    if q%2==0:
        even=1
    else:
        odd=1
if even==1 and odd==1:
    y=sorted(y)
print(*y)