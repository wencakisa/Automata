#ifndef STATE_GUARD_
#define STATE_GUARD_

class State {
public:
  State(const char*);

  const char* getName() const;

  bool getIsStarting() const;
  bool getIsFinal() const;

  void setIsStarting(bool);
  void setIsFinal(bool);

  bool operator==(const State&) const;
private:
  char* name;

  bool isStarting;
  bool isFinal;
};

#endif
