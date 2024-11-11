import math


def func(num_buckets, length, buckets):
    lista = []
    for i in range(num_buckets):
        if(length % buckets[i] == 0): 
            lista.append(buckets[i])
    return length / max(lista)

num_buckets, length = list(map(int, input().split()))
buckets = list(map(int, input().split()))

hours = func(num_buckets, length, buckets)

print(hours)

#hours * buckets[i] = length