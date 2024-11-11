'''
In the name of God
'''

test = int(input())

i = 0
while i < test:
    
    length = int(input())
    lst = list(map(int, input().split()))
    
    for j in range(length):
        lst.remove(lst[j])
    
    for k in range(length):
        print(lst[k], end = " ")

    i += 1