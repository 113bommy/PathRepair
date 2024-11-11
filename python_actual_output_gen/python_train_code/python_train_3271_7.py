n = input()
b = input().split()
a = list(map(int, b))
def thanos(array, size):
    x = int(size)//2
    if array == sorted(array):
        print("helo")
        return(len(array))
    else:
        print("hai")
        return max(thanos(array[:x], x), thanos(array[x:], x))
    return None
print(thanos(a, n))