//QOSA core definition header
#include "qosa_def.h"
//Include QOSA system API header
#include "qosa_sys.h"
//Include QOSA log system header file
#include "qosa_log.h"

//Define log information
#define QOS_LOG_TAG   LOG_TAG_DEMO

//Define stack size of hello world task as 1024 bytes
#define QUECOS_HELLO_WORLD_DEMO_TASK_STACK_SIZE 1024
//Define hello world task priority as normal
#define QUECOS_HELLO_WORLD_DEMO_TASK_PRIO QOSA_PRIORITY_NORMAL

//Declare global task handle and initialize as NULL
static qosa_task_t g_quec_hello_world_demo_task = QOSA_NULL;

//Define the main process function for the hello world task
static void quec_hello_world_demo_process(void *ctx)
{
    //Initialize counter
    int hello_world_cnt = 0;

    //Infinite loop
    while (1)
    {
        //Print verbose log showing the current count value
        QLOGV("hello world count=%d", hello_world_cnt++);
        //Task sleeps for 1000 ms (1 second)
        qosa_task_sleep_ms(1000);
    }
}

//Initialization function for the hello world demo
void quec_hello_word_init(void)
{
    //Print verbose log indicating entry into hello world demo
    QLOGV("enter hello world DEMO !!!");
    //Check if the task has not been created yet
    if (g_quec_hello_world_demo_task == QOSA_NULL)
    {
        //Create hello world task
        qosa_task_create(
            &g_quec_hello_world_demo_task,                  //Task handle pointer
            QUECOS_HELLO_WORLD_DEMO_TASK_STACK_SIZE,        //Task stack size
            QUECOS_HELLO_WORLD_DEMO_TASK_PRIO,              //Task priority
            "hello_world_demo",                             //Task name
            quec_hello_world_demo_process,                  //Task handler
            QOSA_NULL);                                     //Task parameter
    }
}
