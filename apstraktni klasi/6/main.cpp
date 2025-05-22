#include<iostream>
#include<cstring>

using namespace std;

class Task {
protected:
    char id[5];
public:
    Task() {}

    Task(char *id) {
        strcpy(this->id, id);
    }

    Task(const Task &t) {
        strcpy(id, t.id);
    }

    Task &operator=(const Task &t) {
        if (this != &t) {
            strcpy(id, t.id);
        }
        return *this;
    }

    char *getID() {
        return id;
    }

    ~Task() {}

    virtual int getOrder() = 0;

    virtual void print() = 0;

    friend bool operator==(Task *t1, Task &t2) {
        if (strcmp(t1->id, t2.id) == 0 && t1->getOrder() == t2.getOrder())
            return true;
        else
            return false;
    }
};

class TimedTask : public Task {
private:
    int time;
public:
    TimedTask() : Task() {}

    TimedTask(char *id, int time) : Task(id) {
        this->time = time;
    }

    TimedTask(const TimedTask &tt) : Task(tt) {
        time = tt.time;
    }

    TimedTask operator=(const TimedTask &tt) {
        if (this != &tt) {
            strcpy(id, tt.id);
            time = tt.time;
        }
        return *this;
    }

    ~TimedTask() {}

    int getOrder() {
        return time;
    }

    void print() {
        cout << "TT->" << id << ":" << time << endl;
    }
};

class PriorityTask : public Task {
private:
    int priority;
public:
    PriorityTask() : Task() {}

    PriorityTask(char *id, int priority) : Task(id) {
        this->priority = priority;
    }

    PriorityTask(const PriorityTask &pt) : Task(pt) {
        priority = pt.priority;
    }

    PriorityTask operator=(const PriorityTask &pt) {
        if (this != &pt) {
            strcpy(id, pt.id);
            priority = pt.priority;
        }
        return *this;
    }

    int getOrder() {
        return priority;
    }

    void print() {
        cout << "PT->" << id << ":" << priority << endl;
    }

    ~PriorityTask() {}
};

void sortiraj(Task **tasks, int n) {
    int i, j;
    Task *tmp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (tasks[i]->getOrder() > tasks[j]->getOrder()) {
                tmp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = tmp;
            }
        }
    }
}

void scheduleTimedTasks(Task **tasks, int n, int t) {
    sortiraj(tasks, n);
    TimedTask *tt;
    for (int i = 0; i < n; i++) {
        tt = dynamic_cast<TimedTask *>(tasks[i]);
        if (tt && tt->getOrder() < t)
            tt->print();
    }
}

void schedulePriorityTasks(Task **tasks, int n, int p) {
    sortiraj(tasks, n);
    PriorityTask *pt;
    for (int i = 0; i < n; i++) {
        pt = dynamic_cast<PriorityTask *>(tasks[i]);
        if (pt && pt->getOrder() < p)
            pt->print();
    }
}

int main() {
    int testCase;
    int n;
    cin >> testCase;

    if (testCase == 0) {
        cin >> n;
        Task **tasks;
        tasks = new Task *[n];
        for (int i = 0; i < n; i++) {
            char id[5];
            int timeOrPriority;
            int type; //0 za timed, 1 za priority
            cin >> type >> id >> timeOrPriority;
            if (type == 0)
                tasks[i] = new TimedTask(id, timeOrPriority);
            else
                tasks[i] = new PriorityTask(id, timeOrPriority);
            //tasks[i]->print();
        }

        cout << "SCHEDULING PRIORITY TASKS WITH PRIORITY DEGREE LESS THAN 10" << endl;
        schedulePriorityTasks(tasks, n, 10);

    } else if (testCase == 1) {
        cin >> n;
        Task **tasks;
        tasks = new Task *[n];
        for (int i = 0; i < n; i++) {
            char id[5];
            int timeOrPriority;
            int type; //0 za timed, 1 za priority
            cin >> type >> id >> timeOrPriority;
            if (type == 0)
                tasks[i] = new TimedTask(id, timeOrPriority);
            else
                tasks[i] = new PriorityTask(id, timeOrPriority);
            //tasks[i]->print();
        }


        cout << "SCHEDULING TIMED TASKS WITH EXECUTION TIME LESS THAN 50" << endl;
        scheduleTimedTasks(tasks, n, 50);
    } else {
        TimedTask *tt1 = new TimedTask("11", 10);
        TimedTask *tt2 = new TimedTask("11", 11);
        TimedTask *tt3 = new TimedTask("11", 11);
        PriorityTask *pp1 = new PriorityTask("aa", 10);
        PriorityTask *pp2 = new PriorityTask("11", 10);

        cout << (tt1 == (*tt2)) << endl;
        cout << (tt2 == (*tt3)) << endl;
        cout << (pp1 == (*pp2)) << endl;
        cout << (pp2 == (*tt1)) << endl;
    }

    return 0;
}
