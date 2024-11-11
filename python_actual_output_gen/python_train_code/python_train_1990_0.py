def str_to_sum(n):
    s = 0
    for i in n:
        s += int(i)
    return s
n = input()
s = 0
s = str_to_sum(n)
if s%4 == 0:
    print(n)
else:
    for j in range(1,5):
        s = str_to_sum(str(int(n)+j))
        if s%4 == 0:
            print(int(n)+j)
            break
        
