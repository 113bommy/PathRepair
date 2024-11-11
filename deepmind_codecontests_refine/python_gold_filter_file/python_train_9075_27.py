def main(s):
    fours = len(list(filter(lambda c: c == '4', s)))
    sevens = len(list(filter(lambda c: c == '7', s)))
    if fours == 0 and sevens == 0:
        return -1
    if fours >= sevens:
        return "4"
    else:
        return "7"

print(main(list(input())))
