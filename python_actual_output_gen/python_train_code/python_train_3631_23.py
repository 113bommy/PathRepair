n,m=map(int, input().split())
dic=dict()
for i in range(m):
    l1,l2=input().split()
    dic[l1]=l2

lecture=input()
lec_list=list(lecture.split(" "))

for i in lec_list:
    if len(i) >= len(dic[i]):
        print(dic[i],end=" ")
    else:
        print(i,end=" ")