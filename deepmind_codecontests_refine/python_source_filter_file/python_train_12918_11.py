n, k = list(map(int,input().split()))
diff = list(map(int,input().split()))

def find_k_best(k, n, diff):
    k_best_value = [0]*k
    k_best_index = [0]*k

    for i in range(1,n):
        j = 0
        while j < k:
            if diff[i]>=k_best_value[j]:
                k_best_value = k_best_value[:j] +  [diff[i]]  + k_best_value[j:-1]
                k_best_index = k_best_index[:j] + [i] + k_best_index[j:-1]
                j = k
            j += 1
    
    return k_best_value, k_best_index

v, i = find_k_best(k, n, diff)
s = sum(v)
i.sort()
i[-1] = n-1

idx = [i[0] + 1]
for t in range(1,len(i)):
    idx.append(i[t] - i[t-1])


print(sum(v))

str_idx = ""
for t in range(len(idx)):
    str_idx += str(idx[t]) + " "

print(str_idx[:-1])
