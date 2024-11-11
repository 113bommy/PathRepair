def main():
    n, k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]

    index, boxes, left = 1, 0, n
    for i, e in enumerate(a):
        cur_left = n % e
        if cur_left < left:
            left, index, boxes = cur_left, i, n // e
    
    print(index + 1, boxes)



if __name__ == '__main__':
    main()
