def get_index(string):
    for i in range(len(string)):
        if string[i] != "0":
            return i
    return -1


for _ in range(int(input())):
    n = int(input(()))
    string = input()
    count = 0
    while True:
        if string[-1] == "0":
            indx = get_index(string)
            if indx == -1:
                break
            count += 1
            string = string[:indx] + "0" + string[indx+1:-1] + string[indx]
        else:
            count += int(string[-1])
            string = string[:-1] + "0"
    print(count)