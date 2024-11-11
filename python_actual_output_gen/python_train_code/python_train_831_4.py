I = lambda:int(input())
ID = lambda:map(int, input().split())
IL = lambda:list(ID())
n = I()
a = IL()
odd = even =0
for i in a:
    if i&1:
        odd+=1
    else:
        even+=1
if odd == 0:
    print('Second')
    exit()
if even == 0:
    print('First')
    exit()
if even == odd:
    print('Second')
    exit()
print('First')