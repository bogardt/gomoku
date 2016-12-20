//
// Referee.hpp for Gomoku in /home/mikaz3/Tek3/B5/AI/Gomoku/mSFML/includes
//
// Made by Thomas Billot
// Login   <mikaz3@epitech.net>
//
// Started on  Wed Nov 30 12:23:53 2016 Thomas Billot
// Last update Thu Dec 15 22:37:16 2016 Thomas Billot
//

#ifndef			_GOMOKUREFEREE_HPP_
# define		_GOMOKUREFEREE_HPP_

# include		"Map.hpp"
# include		"IReferee.hpp"
# include		<memory>

class			GomokuReferee : public IReferee
{
public:

  class DirectionsHelper
  {
    static const Map::Coordinates _directions[8];
    
  public:
    DirectionsHelper() {}
    ~DirectionsHelper() {}
    Map::Coordinates getNextDirection() const
    {
      static int i = 0;

      if (i == 7)
	i = -1;
      return _directions[++i];
    }
  };
  
  enum			Direction
    {
      NORTH		= -19,
      NORTH_EAST	= -18,
      EAST		= 1,
      SOUTH_EAST	= 20,
      SOUTH		= 19,
      SOUTH_WEST	= 18,
      WEST		= -1,
      NORTH_WEST	= -20,
    };

   static constexpr GomokuReferee::Direction directions[8] = {NORTH,
							      NORTH_EAST,
							      EAST,
							      SOUTH_EAST,
							      SOUTH,
							      SOUTH_WEST,
							      WEST,
							      NORTH_WEST};

private:

  Map				&_map;
  int				_whiteCapturedPieces;
  int				_blackCapturedPieces;
  Map::CaseState		_pawnToCheck;
  Map::CaseState		_ennemyPawn;

public:
  // GomokuReferee();
  explicit			GomokuReferee(Map &map);
  virtual			~GomokuReferee();

  void				setMap(Map &map);
  
  virtual IReferee::GameState	validatePlayerAction(int CoordX, int CoordY, const bool turn);
  virtual void			resetReferee();
  virtual int			getP1Score();
  virtual int			getP2Score();
  bool				testDoubleThree(Map::Coordinates coordinates);
  void				testCapture(Map::Coordinates coordinates);

private:
  IReferee::GameState		testMap();
  void				setTurn(int CoordX, int CoordY, const bool turn);

  void				testCaptureInDirection(GomokuReferee::Direction direction, Map::Coordinates coordinates);
  bool				hasCapture(Map::Coordinates coordinates, int xInc, int yInc);
  void				capturePieces(Map::Coordinates coordinates, int xInc, int yInc);

  std::vector<int>		testAlignement(Map::Coordinates coordinates);
  int				testAlignementInDirection(GomokuReferee::Direction direction, Map::Coordinates coordinates);
  int				countAlignement(Map::Coordinates coordinates, int xInc, int yInc);

  bool				hasFiveInARow(GomokuReferee::Direction direction, Map::Coordinates coordinates);
  IReferee::GameState		TestFiveInARow(int CoordX, int CoordY, int i, Map::CaseState player);
  bool				simulateCapture(Map::Coordinates coordinates, Map::CaseState rivals, int xInc, int yInc, int xIncBack, int yIncBack, int i);

void				initIncDirection(GomokuReferee::Direction direction, int &xInc, int &yInc);
  GomokuReferee::Direction	invertDirection(GomokuReferee::Direction direction);
  std::unique_ptr<std::vector<Map::Coordinates>> FindPattern3inLine(Map::Coordinates coordinates);
  std::unique_ptr<std::vector<Map::Coordinates>> FindPattern3inLine(Map::Coordinates coordinates, Map::Coordinates forbiddenDir);
  std::unique_ptr<std::vector<Map::Coordinates>> FindPattern2inLine1Empty(Map::Coordinates coordinates);
  std::unique_ptr<std::vector<Map::Coordinates>> FindPattern2inLine1Empty(Map::Coordinates coordinates, Map::Coordinates forbiddenDir);
  bool				checkPattern1(Map::Coordinates c, Map::Coordinates d);
  bool				checkPattern2(Map::Coordinates c, Map::Coordinates d);
  Map::Coordinates		Pattern1(Map::Coordinates c);
  Map::Coordinates		Pattern2(Map::Coordinates c);
  bool				checkForEnnemyPawn(std::vector<Map::Coordinates> &v);
  std::unique_ptr<std::vector<Map::Coordinates>> testPattern1inDirection(const Map::Coordinates &coordinates, Map::Coordinates);
  std::unique_ptr<std::vector<Map::Coordinates>> testPattern2inDirection(const Map::Coordinates &coordinates, Map::Coordinates);
  std::unique_ptr<std::vector<Map::Coordinates>> testPattern1(const Map::Coordinates &coordinates);
  std::unique_ptr<std::vector<Map::Coordinates>> testPattern1(const Map::Coordinates &coordinates, Map::Coordinates forbiddenDir);
  std::unique_ptr<std::vector<Map::Coordinates>> testPattern2(const Map::Coordinates &coordinates);
  std::unique_ptr<std::vector<Map::Coordinates>> testPattern2(const Map::Coordinates &coordinates, Map::Coordinates forbiddenDir);
  bool						checkIfFree(const std::vector<Map::Coordinates> &v);
  int				getWhiteCapturedPieces();
  int				getBlackCapturedPieces();

};

int				testAlignementInDirection(GomokuReferee::Direction direction,
							  const Map &map,
							  int index,
							  Map::CaseState color);
bool				testCaptureInDirection(GomokuReferee::Direction direction,
						       const Map &map,
						       Map::Coordinates coordinates);

bool				testCaptureInDirection(GomokuReferee::Direction direction,
						       const Map &map,
						       int index,
						       Map::CaseState color);

#endif			/* _GOMOKUREFEREE_HPP_ */
