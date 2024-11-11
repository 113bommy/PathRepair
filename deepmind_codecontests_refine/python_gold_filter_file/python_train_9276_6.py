

def main_function():
    input_list = [[int(i) for i in input().split(" ")][1:] for h in range(int(input()))]
    output_list = []
    for i in range(len(input_list[0])):
        current_tram = input_list[0][i]
        should_tram_be_added = True
        for j in range(1, len(input_list)):
            is_tram_in_the_list = False
            for k in range(len(input_list[j])):
                if input_list[j][k] == current_tram:
                    is_tram_in_the_list = True
                    break
            if not is_tram_in_the_list:
                should_tram_be_added = False
                break
        if should_tram_be_added and not str(current_tram) in output_list:
            output_list.append(str(current_tram))
    return " ".join(output_list)



print(main_function())