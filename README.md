# oopcpp

Notification:

solution uses the Observer Design Pattern (Please refer to the GoF Patterns book)

    A College has many Departments. A College also has students. Department has Faculty. Students are also enrolled in Department.
    Department has a Noticeboard. Noticeboard occasionally gets new messages (by a timer thread - see below).
    Noticeboard will notify any class that implement interface Observer will get Notification as a callback.
    Both Student and Faculty classes implement Observer
    In the attached solution,  Students and Faculty indicate their interest (or not) in getting notifications. As usual objects are arranged in the main().
    Then two timer threads start.
        One of them posting notice to notice board.. which eventually makes to all interested parties.
        The second timer thread kills the first thread and also terminates
