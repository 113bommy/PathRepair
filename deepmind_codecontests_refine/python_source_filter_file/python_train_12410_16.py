def main(k1, k2):
    while True:
        if min(k2) > max(k1):
            c = find(k1, max(k1))
            k2.append(k1[c])
            del k1[c]
            print(k1, k2)
        elif max(k1) > min(k2):
            c = find(k2, min(k2))
            k1.append(k2[c])
            del k2[c]
            print(k1, k2)
        if len(k1) == 0:
            return 'no'
        if len(k2) == 0:
            return 'yes'


def find(arr, i):
    index = 0
    while index < len(arr):
        if arr[index] == i:
            return index
        index = index + 1


if __name__ == '__main__':
    t = int(input())
    for t_itr in range(t):
        arr = list(map(int, input().rstrip().split()))
        n = arr[0]
        a = arr[1]
        b = arr[2]
        k1 = list(map(int, input().rstrip().split()))
        k2 = list(map(int, input().rstrip().split()))
        res = main(k1, k2)
        print(res)

