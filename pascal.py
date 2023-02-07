"""
The following python "script" can be ran to help collect 
process time for multiple iterations. External scripts like this are 
common in research.    


Sample execution would be to write out the standard out (print) to a file. For example

python3 pascal.py 30 csv  > pascal_run.csv

python3 pascal.py 30 > pascal_table.md
"""

import subprocess
import time 
import sys

EXEC = ["./pascal.out"] 
COMMON_ARG_FORMAT = "{n} {type} 0"
FORMAT = "markdown"

def run_single(n: int, type: int) -> float:
    """Run a single instance collecting the total execution time"""
    args = COMMON_ARG_FORMAT.format(n=n, type=type)
    start = time.time()
    subprocess.call(EXEC + args.split())
    end = time.time()
    return end - start

def build_row(n:int) -> str:
    """_summary_

    Args:
        n (_type_): _description_
    """
    iterative = run_single(n, 0)
    recursive = run_single(n, 1)
    dynamic_programming = run_single(n, 2)
    if FORMAT == "markdown":
        return f"| {n:<4} | {iterative:.5f} | {recursive:.5f} | {dynamic_programming:.5f} |"
    return f"{n},{iterative:.5f},{recursive:.5f},{dynamic_programming:.5f}"



def table_header() -> str:
    """Returns a markdown table header for this data set"""
    if FORMAT == "markdown":
        return "| n | Iterative | Recursive | Dynamic Programming |\n" + \
               "|--|:--:|:--:|:--:|"
    return "n,Iterative,Recursive,Dynamic Programming"



def main(n):
    print(table_header())
    for i in range(1,n+1):
        print(build_row(i))

## note while using argv directly, there are better tools for this like pip click
if __name__ == "__main__":
    n = 30 if len(sys.argv) < 2 else int(sys.argv[1])   
    if len(sys.argv) == 3:
        FORMAT = "csv"
    main(n)
