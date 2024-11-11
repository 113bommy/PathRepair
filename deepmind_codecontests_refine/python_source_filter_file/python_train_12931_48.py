s=input().split()
list1=list(input().split())
list2=list(input().split())
q=int(input())
while q>0:
    num=int(input())
    print(list1[num%int(s[0])-1],list2[num%int(s[1])-1])
    q-=1