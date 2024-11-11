"""
Usage:
    python solution.py < input.txt > solution_output.txt

Testing:
    pytest test_solution.py
"""


def get_input() -> str:
    """
    Loops throw the stdio to fetch input data
    It may change according to the input of the problem
    Args:
        inputs_number: Number of lines of the input
                       Needs to be manually changed in case of
                       multiple lines input
    Returns:
        raw_input_data: The input of a problem
    """
    raw_input_data = ""
    number_of_gems = input()
    try:
        for _ in range(int(number_of_gems)):
            raw_input_data += input() + "\n"
    except:
        pass
    return raw_input_data


def process_input(raw_input_data: str):
    """
    Here the goal is to make the raw input
    equals to the input provided by the problem example
    (like the input strings on the test_solution.py)
    Args:
        raw_input_data:

    Returns:
        data: formatted string
    """
    data = raw_input_data.strip()
    return data


def solve(raw_input_data):
    """
    Here you solve the problem, happy coding!!
    Args:
        raw_input_data: the output of the get_input() function

    Returns:
        n: the solution of the problem
    """
    present_gems = process_input(raw_input_data).split("\n")
    
    infinity_gems = {
        "purple": "Power",
        "green": "Time",
        "blue": "Space",
        "orange": "Soul",
        "red": "Reality",
        "yellow": "Mind",
    }
    
    if len(present_gems[0]) > 1:
        answer = str(6 - len(present_gems)) + "\n"
    
        for gem in present_gems:
            infinity_gems.pop(gem)
    else:
        answer = str(6) + "\n"
        
    for gem in infinity_gems.values():
        answer += gem + "\n"
    
    return answer[:-1]


if __name__ == "__main__":

    # Change input lines number here
    while True:
        try:
            input_data = get_input()
            answer = solve(input_data)
            print(answer)
        except:
            break
