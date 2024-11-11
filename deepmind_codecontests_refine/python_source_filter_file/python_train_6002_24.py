walruses,chips=map(int,input().split())
a=True
while a:
    for i in range (walruses):
        if chips>i+1:
            chips=chips-(i+1)
        else:
            a=False
print (chips)