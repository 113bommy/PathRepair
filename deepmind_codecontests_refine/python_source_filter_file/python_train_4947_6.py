def main():

    a = input()
    b = input()

    boolean = False
    index_to_start_a = 0
    index_to_start_b = 0
    while index_to_start_a < len(a) and [index_to_start_a] == "0":
        index_to_start_a += 1

    while index_to_start_b < len(b) and [index_to_start_b] == "0":
        index_to_start_b += 1

    a = a[index_to_start_a:]
    b = b[index_to_start_b:]

    length_a = len(a)
    length_b = len(b)
    if length_a > length_b:
        print(">")
    elif length_a < length_b:
        print("<")

    else:
        for k in range(length_a):
            if a[k] > b[k]:
                print(">")
                boolean = True
                break
            if a[k] < b[k]:
                print("<")
                boolean = True
                break

        if not boolean:
            print("=")






main()




