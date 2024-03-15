#include<iostream>
#include<cstdlib>

using namespace std;

#include"genQueue.h"                                                                //Importing "genQueue.h" so that we can use the queue class defined in it

 // Defining options method, It randomly selects one index from the the percents array
int option(int percents[]){                                                           //function definition                                            
    register int i = 0,choice = rand()%100+1,perc;                                   // declare i,choice(bein   g intitalized with a random value between 1 and 100),perc;
    for(perc = percents[0];perc < choice;i++)                                        // now we add the value of percents[i] into the perc untill that value is less than choice
    perc += percents[i+1];              
    return i;                                                                         // the index after which the loop breaks is returned as our random ans
}

int main() {
    int arrivals[] = {15,20,25,10,30};                                               //percentange of time intervals with ith(index) no of customers i.e for 15% intervals theere are 0 customers
    int service[] = {0,0,0,10,5,10,10,0,15,25,10,15};                                 // random values(in seconds) that might be selected as service time for a particualr customer
    int clerks[] = {0,0,0,0};                                                         // the curr occupied time for each clerk intialized as 0
    int numofClerks = sizeof(clerks)/sizeof(int);                                      // calculating no of clerks
    int customers,t,i,numofMinutes = 100,x;

    /*  Now we are going to perform the action for 100 minutes
        For each minute we will randomly select the number of customers
        so for every iteration every clerk has 60 seconds to service them
        and assign them to the clerks if any customer for that minute remains unserviced that adds to the waiting time
         */

    double maxWait= 0.0,currWait  = 0.0,thereisLine = 0.0;          // intializing the max_wait_time,curr_wait_time and no of people waiting to be serviced as 0
    Queue<int> simulQ;                                              // declaring a queue
    cout.precision(2);                                              // setting the percision of cout to display values upto 2 decimal points

    for(t = 1;t <= numofMinutes;t++){                               // iterating 100 times and calculating wait time for each minute 
        cout<<" t = "<<t<<endl;                                           //Display which time interval are we currently in

        /*This loop below deals with pending time from previous iteration*/

        for(i = 0;i < numofClerks;i++){                            
            if(clerks[i] < 60) clerks[i] = 0;                       // check if any clerk has pending work 1. if he has less than 60 seconds of work(use the time from the current interal)
            else clerks[i] -= 60;                                   // else if he has even more use the entire minute to reduce the workload
        }
        customers = option(arrivals);                              // calculate random no of cutomers for current time interval 
        for(i = 0;i < customers;i++){                              
            x = option(service)*10;                                // assign each cutomer some random service time
            simulQ.enqueue(x);                                     // enqueue the customer into the waiting queue
            currWait += x;                                         // increase the net waiting time for current iteration
        }

                                                                    // start servicing the customers
        for (i = 0; i < numofClerks && !simulQ.isEmpty(); )         // loop untill we run out of free clerks or cutomers
            if (clerks[i] < 60) {                                       // if any clerk has less than 60 seconnd of present work he can service more customers
            x = simulQ.dequeue();                                       // remove one customer from queue 
            clerks[i] += x;                                             // assign the customer to the clerk
            currWait -= x;                                                 // reduce the curr_wait as a customer is being serviced                
            }
            else i++;                                                   // else move onto next clerk
                                                                    //this process will repeat untill all clerks are assigned

        if (!simulQ.isEmpty()) {                                    // if there are still cutomers in the queue they will have to wait for next interval 
            thereisLine++;                                              // increment the thereisLine implying this interval will have a line
            cout << " wait = " << currWait/60.0<<endl;                        //find out the wait in minutes
        if (maxWait < currWait)                                     // if wait value is more than max_wait update it 
            maxWait = currWait;
        }
        else cout << " wait = 0"<<endl;                                      
        }
        cout << "\nFor " << numofClerks << " clerks, there was a line "  // finally display how many percentage of time intervals had a line 
        << thereisLine/numofMinutes*100.0 << "% of the time;\n"            
        << "maximum wait time was " << maxWait/60.0 << " min.";           // dislpay the  maximum time interval through out the process
        return 0;
}