n = int(input())
s = list(input())

alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
dct = {i:j for i,j in zip(alphabet, range(26))}

def countingSort(arr, dict_):
    counts = [0]*26
    for i in arr:
        counts[dict_[i]] += 1
    return counts

many = False
res = countingSort(s, dct)
for d in range(len(res)):
    if res[d] > 1:
        many = True
        break

ans = None
if n == 1:
    ans = 'Yes'
elif many == False:
    ans = 'No'
else:
    ans = 'Yes'
print (ans)