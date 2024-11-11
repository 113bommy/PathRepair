
def find_best(number , misha):
    right = number - misha
    if right < misha - 1:
        print(misha - 1)
    else:
        print(misha + 1)


if __name__ == "__main__":
    number , misha = input().split(" ")
    if int(number) == 1:
        print(1)
    else:
        find_best(int(number) , int(misha))

    