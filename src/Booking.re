type state =
  | OneWay
  | RoundTrip;

let stateToString =
  fun
  | OneWay => "OneWay"
  | RoundTrip => "RoundTrip";

let s = React.string;

let formTargetValue = event => ReactEvent.Form.target(event)##value;

[@react.component]
let make = (~name) => {
  let (state, setState) = React.useState(() => OneWay);

  let handleChange = (state, _) => {
    setState(_ => state);
  };

  let departOn =
    <label className="mr-8">
      <p className="mb-2 text-center"> {s("DepartOn")} </p>
      <input className="border-2 border-grey-500" type_="date" />
    </label>;

  let returnOn =
    <label className="mr-8">
      <p className="mb-2 text-center"> {s("Return On")} </p>
      <input className="border-2 border-grey-500" type_="date" />
    </label>;

  <div className="bg-blue-200">
    <h1 className="text-5xl text-center"> {React.string("Booking")} </h1>
    <div className="p-8 flex items-center justify-center">
      <label className="mr-8">
        <input
          onChange={handleChange(OneWay)}
          name
          value={stateToString(OneWay)}
          checked={OneWay == state}
          className="mr-2"
          type_="radio"
        />
        <span> {s("OneWay")} </span>
      </label>
      <label className="mr-8">
        <input
          onChange={handleChange(RoundTrip)}
          name
          value={stateToString(RoundTrip)}
          checked={RoundTrip == state}
          className="mr-2"
          type_="radio"
        />
        <span> {s("Round Trip")} </span>
      </label>
    </div>
    <div className="flex justify-center">
      {switch (state) {
       | OneWay => departOn
       | RoundTrip => <> departOn returnOn </>
       }}
    </div>
  </div>;
};
