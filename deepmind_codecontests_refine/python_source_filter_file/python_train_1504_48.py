list1=["","","",""]
n=int(input())
for _ in range(n):
    list2=[x for x in input().split()]
    val=int(list2[1])
    if list2[2]=='N':

        if list2[0]=='>=':
            list2[0]='<'

        elif list2[0]=='>':
            list2[0]='<='

        elif list2[0]=='<=':
            list2[0]='>'

        elif list2[0]=='<':
            list2[0]='>='

    if list2[0]=='>=':
        if list1[1]=="":
            list1[0]='['
            list1[1]=val
        else:
            if list1[1]<val:
                list1[1]=val
                list1[0]='['
    elif list2[0]=='>':
        if list1[1]=="":
            list1[0]='('
            list1[1]=val
        else:
            if list1[1]<val:
                list1[1]=val
                list1[0]='('
    elif list2[0]=='<=':
        if list1[2]=="":
            list1[3]=']'
            list1[2]=val
        else:
            if list1[2]>val:
                list1[2]=val
                list1[3]=']'
    elif list2[0]=='<':
        if list1[2]=="":
            list1[3]=')'
            list1[2]=val
        else:
            if list1[2]>val:
                list1[2]=val
                list1[3]=')'

if list1[0]=='(':
    list1[1]+=1
if list1[3]==')':
    list1[2]-=1

if list1[0]=="" or list1[3]=="":
    if list1[0]=="":
        print(list1[2])
    else:
        print(list1[1])
else:
    if list1[1]>list1[2]:
        print('Impossible')
    else:
        print(list1[1])
