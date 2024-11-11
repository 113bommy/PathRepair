n = int(input())
array = list(map(int, input().split()))
if n == 1:
    print('yes')
    print(*(1,1))
    exit()
dsc = 0;
l = r = None;
for i in range(n):
    if i == 0:
        if array[i+1] < array[i]:
            dsc = 1; l = 0
    else:
        if dsc == 0:
            if array[i] < array[i-1]:
                dsc = 1; l = i-1
        else:
            if array[i] > array[i-1]:
                dsc = 0; r = i-1;
                break

if l == None:
    print('yes')
    print(*(1,1))
else:
    if r == None:
        ans = array[:l] + array[l:]
        if ans == sorted(array):
            print('yes')
            print(*(l+1, n))
        else:
            print('no')
    else:
        ans = array[:l] + array[l:r+1][::-1] + array[r+1:]
        if ans == sorted(array):
            print('yes')
            print(*(l+1, r+1))
        else:
            print('no')

            

        
