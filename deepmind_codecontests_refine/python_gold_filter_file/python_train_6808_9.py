a = input()
s = ''
i = 0
while i<len(a):
    if a[i] == '.':
        s = s+'0'
        i = i+1
    elif a[i] == '-':
        if a[i+1] == '.':
            s = s+'1'
        else:
            s = s+'2'
        i = i +2
print(s)