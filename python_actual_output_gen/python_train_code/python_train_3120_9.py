n, x = map(int, input().split())
s = sum(map(int, input().split()))
s=abs(s)
print(abs(s//x) + (s>round(s)))




# r, c = map(int,input().split())
# ir, ic =[],[]
# m = []
# for i in range(r):
#     s = input()
#     m = m + [s]
#     for j in range(len(s)):
#         if s[j] == 'S':
#             ir  = ir + [i]
#             ic  = ic + [j]
# numb = 0
# print(ir)
# print(ic)
# print(m)
# for i in m:
#     for j in range(len(i)):
#         if i not in ir or j not in ic:
#             numb +=1
# print(numb)
