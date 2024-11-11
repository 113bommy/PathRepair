def print_results(rows):
    for item in rows:
        print(item)


def main():
    rows = []

    for i in range(6):
        rows.append(input())

    new_row = ""
    for i, row in (enumerate(rows)):
        if row[3] == '.':
            rows[i] = row[:3] + "P" + row[4:]
            print_results(rows)
            return
        elif row[4] == '.':
            rows[i] = row[:4] + "P" + row[5:]
            print_results(rows)
            return
        
        if (new_row != ""):
            rows[i - 1] = new_row
            print_results(rows)
            return

        if row[0] == '.':
            new_row = "P" + row[1:]
        elif row[1] == '.':
            new_row = row[0] + "P" + row[2:]
        elif row[6] == '.':
            new_row = row[:6] + "P" + row[7]
        elif row[7] == '.':
            new_row = row[:7] + "P"
    
    rows[5] = new_row
    print_results(rows)
    return

main()