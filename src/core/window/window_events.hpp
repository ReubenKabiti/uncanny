namespace UC
{
  enum class EventType
  {
    WINDOW_CLOSE,
    MOUSEDOWN,
    MOUSEUP,
    KEYDOWN,
    KEYUP,
  };
  class WindowEvent
  {
  public:
    WindowEvent(EventType eventType) : m_eventType(eventType) {}
    virtual ~WindowEvent() {}
    inline EventType getType() { return m_eventType; }

  private:
    EventType m_eventType;
  };
}