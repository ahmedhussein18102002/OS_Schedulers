# Multi core Schedulars

This project implements different schedulars algorism that handle scheduling proccesses enters the system.
The number of cores can be determined before running the program, making the program more flexable.

## Installation

For compiling, and extracting the exutable file, run:

```bash
bash compile.sh
```

This will make a file called `program`, which is the executable file.

To run the program you need to provide two arguments

1. schedular name
2. The file that has the processes

```
./program <SCHEDULAR> <PROCESSES_FILE_DESTINATION>
```

We made a short hand to compile and run.

This will

1. compile the code
2. extract the executable file `program`
3. Run the program with the provided schedular argument
4. pick the txt file in the `/test` folder with the same name of the schedular. i.e. `/test/<SCHEDULAR>.txt`.

```bash
bash run.sh <SCHEDULAR>
```

**NOTE**: If you are using `chmod`, instead of `bash` you can compile using this command

## Configurations

In `config.h`, all MACROS are defines which configurates how the schedular will work.

The configuation file has the following params:

1. `STEP`: (STEP duration) in c_milli_seconds
2. `NUM_CORES`: Number of cores (each core can run only one proccess at a STEP)
3. `IO_TIME`: The duration each I/O operation will take expressed in STEPS
4. `MAX_PRIORITY`: The maximum priority queue level (used in MLFQ schedular)
5. `PRIORITY_BOOST`: The number of steps after which the MLFQ schedular will level up all proccesse to the maximum queue level

## File Structure

- The project root file, which has the `main()` funtion, is `main.c`. This is the file which is used to run the program.
- All `*.h` files, which represent the prototype of the function, is places in `interfaces` folder
- Proccess variables and functions in addition to global variables are existed in `/data`
- In `/helpers`, there are necessary files, which is used in calculating, and logging results into the terminal
- Schedulars different Algorisms are existed in `/schedulars`, where each schedular algorism is named by the name of the algorism.

| File                             | Code |                                                                                                                                           Short Description |
| :------------------------------- | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------------------: |
| main.c                           | 249  | The beginning of the program starts from this file. stors the processes in the file passed as argument and run the schedular that is passed as argument too |
| data/constants.c                 | 15   |                                                                                    Global variables that is being used by more than one file in the program |
| data/proccess.c                  | 98   |                                       All processes logic, initialization, execution, checking. In addition to IO processes functionality are existed in it |
| helpers/math.c                   | 17   |                                                                                                               Mathimatical funcionalies used in the program |
| helpers/printer.c                | 38   |                                                                              Responsible for printing a report for all proccesses in the ent of the program |
| helpers/simulator.c              | 85   |                                                                                Responsible for simulating the running processes by printing its information |
| helpers/utils.c                  | 15   |                                                                                                                       Utility functions used in the program |
| schedulars/FIFO.c                | 118  |                                                                                                                 First come first served scheduling algorism |
| schedulars/SJF.c                 | 120  |                                                                                                                      Shortest Job First scheduling algorism |
| schedulars/STCF.c                | 119  |                                                                                                       Shortest Time-to-Completion First scheduling algorism |
| schedulars/RR.c                  | 125  |                                                                                                                             Round Robin scheduling algorism |
| schedulars/Priority.c            | 128  |                                                                                                                                Priority scheduling algorism |
| schedulars/MLFQ.c                | 161  |                                                                                                              Multi-Level Feedback Queue scheduling algorism |
| schedulars/Stride.c              | 125  |                                                                                                             Proportional Sharing Stride scheduling algorism |
|                                  |      |                                                                                                                                                             |
| config.h                         | 8    |                                                                                                                     Configuration (Macros Defenitions) file |
| interfaces/data/constants.h      | 11   |                                                                                                                                     data/constant.c headers |
| interfaces/data/proccess.h       | 34   |                                                                                                                                     data/proccess.c headers |
| interfaces/helpers/math.h        | 7    |                                                                                                                                      helpers/math.c headers |
| interfaces/helpers/printer.h     | 8    |                                                                                                                                   helpers/printer.c headers |
| interfaces/helpers/simulator.h   | 15   |                                                                                                                                 helpers/simulator.c headers |
| interfaces/helpers/utils.h       | 4    |                                                                                                                                     helpers/utils.c headers |
| interfaces/schedulars/FIFO.h     | 4    |                                                                                                                                   schedulars/FIFO.c headers |
| interfaces/schedulars/SJF.h      | 4    |                                                                                                                                    schedulars/SJF.c headers |
| interfaces/schedulars/STCF.h     | 4    |                                                                                                                                   schedulars/STCF.c headers |
| interfaces/schedulars/RR.h       | 4    |                                                                                                                                     schedulars/RR.c headers |
| interfaces/schedulars/Priority.h | 4    |                                                                                                                               schedulars/Priority.c headers |
| interfaces/schedulars/MLFQ.h     | 6    |                                                                                                                                   schedulars/MLFQ.c headers |
| interfaces/schedulars/Stride.h   | 4    |                                                                                                                                 schedulars/Stride.c headers |

| Language     | files | blank | comment | code |
| ------------ | ----- | ----- | ------- | ---- |
| C            | 14    | 356   | 381     | 1413 |
| C/C++ Header | 15    | 51    | 12      | 127  |
|              |       |       |         |      |
| SUM:         | 29    | 407   | 393     | 1540 |

## Developers Team And Moderators

### Developers

- Ahmed Khaled Hussein
- Ahmed Hussein Ahmed
- Ahmed hassan Abd-el-mageed
- Islam Nasser Mahmoud

### Moderators

- Doctor: Marwa Yusuf
- Software Engineer: Mohamed Abd-Elmageed

## License

This project is under the MIT License. See `LICENSE` for more information.

## Acknowledgments

Here are some of the services and websites that we used to make this project.

- [ChatGPT(v3.5)](https://chat.openai.com/)
- [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/)
- [Cloc](https://github.com/AlDanial/cloc)
- [GCC compiler](https://github.com/gcc-mirror/gcc)
- [Text Art Generator](https://patorjk.com/software/taag/)
