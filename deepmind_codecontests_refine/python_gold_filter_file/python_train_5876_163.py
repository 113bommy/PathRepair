# n=list(map(int, input().split()))
# s=input()
# s1=[]
# for i in s:
#     s1.append(i)
# for i in range(n[1]):
#     j=0
#     while j<n[0]-1:
#         if s1[j]=='B' and s1[j+1]=='G':
#             s1[j]='G'
#             s1[j+1]='B'
#             j+=1
#         j+=1
# print(''.join(s1))
s=input()
s1=input()
print('YES') if s==s1[-1::-1] else print('NO')
