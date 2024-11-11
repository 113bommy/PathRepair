def zeros_after_one(array):
    for ch in array:
        if ch != "0":
            return False
    return True

nr = input()
ar = [x for x in input().split()]
if min(ar) == "0":
    print(0)
else:
    nr_of_zeros = 0
    bad_number = "0"
    for x in ar:
        nr = str(x)
        if nr[0] == "1" and zeros_after_one(nr[1:]):
            nr_of_zeros += len(nr) - 1
        else:
            bad_number = nr
    if bad_number:
        print(bad_number + "0" * nr_of_zeros)
    else:
        print("1"+"0"*nr_of_zeros)