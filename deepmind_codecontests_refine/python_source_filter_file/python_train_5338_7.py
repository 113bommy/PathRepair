def main(n, a):
    spheres = n//2
    new = []
    i = 0
    while i < spheres:
        new.append(str(a[spheres+i]))
        new.append(str(a[i]))

        i += 1
    if n % 2 != 0:
        new.append(str(a[-1]))
        return f'{str(spheres)}\n{" ".join(new)}'
    else:
        return f'{str(spheres-1)}\n{" ".join(new)}'

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    print(main(n, a))