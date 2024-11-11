import sys
n, k = [int(x) for x in input().split()]

# arr = [2, 0, 1, 9]
ind = [i for i in range(1, k+2)]

# arr = arr[:k+1]
# ind = ind[:k+1]
n=k+1
fnd_sub_arr=[]
for i in range(k+1):
    # sub_arr = arr[:i]+arr[i+1:]
    sub_ind = ind[:i]+ind[i+1:]
    # print(sub_arr)
    print('?', *sub_ind)
    sys.stdout.flush()

    # sub_arr, sub_ind = zip(*sorted(zip(sub_arr, sub_ind)))
    # sub_arr = list(sub_arr)
    # sub_ind = list(sub_ind)

    # fnd_el = sub_arr[m-1]
    # fnd_ind = sub_ind[m-1]
    fnd_el, fnd_ind =[int(x) for x in input().split()]
    fnd_sub_arr.append(fnd_el)

bm1 = max(fnd_sub_arr)
cnt=0
for i in fnd_sub_arr:
    if bm1==i:
        cnt+=1
print ('!', cnt)
sys.stdout.flush()






