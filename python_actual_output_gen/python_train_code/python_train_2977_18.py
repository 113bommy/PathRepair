s = input()
n = len(s)

num_of_a = res = 0

for ch in s :
    if(ch == 'a') :
        num_of_a = num_of_a + 1

if(num_of_a >= n / 2) :
    res = n
else :
    res = num_of_a + num_of_a - 1

print(res)