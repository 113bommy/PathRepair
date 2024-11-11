t = int(input())

b_list =[]
for i in range(2):
    a, b, c, d = map(int, input().split())
    a_list=[a]+[b]+[c]+[d]
    result=max(a_list[0]+a_list[1], a_list[2]+a_list[3])
    b_list+=[result]
for i in b_list:
    print(i)
