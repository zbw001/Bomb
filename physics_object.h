#ifndef PHYSICSObject_H
#define PHYSICSObject_H

class PhysicsObject {
public:
    PhysicsObject();
    ~PhysicsObject();
    void setProcessEnabled(bool enabled);
    bool isProcessEnabled();
    virtual void process(double delta) = 0;
private:
    bool enabled;
};
#endif
