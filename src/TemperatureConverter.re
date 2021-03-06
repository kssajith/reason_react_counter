let celciusToFarenheit = x => x *. 9. /. 5. +. 32.;
let farenheitToCelcius = x => (x -. 32.) *. 5. /. 9.;

let isTemperatureValid = x => !Js.Float.isNaN(x);

[@react.component]
let make = () => {
  let (celcius, setCelcius) = React.useState(_ => 0.);
  // let(farenheit, setFarenheit) = React.useState(_=> 0.);

  let handleCelciusChange = event => {
    let formTargetValue =
      ReactEvent.Form.target(event)##value |> Js.Float.fromString;
    if (isTemperatureValid(formTargetValue)) {
      setCelcius(_ => formTargetValue);
    };
  };

  let handleFarenheitChange = event => {
    let formTargetValue =
      ReactEvent.Form.target(event)##value |> Js.Float.fromString;
    if (isTemperatureValid(formTargetValue)) {
      setCelcius(_ => formTargetValue |> farenheitToCelcius);
    };
  };

  <div className="flex bg-blue-200 p-16 justify-center">
    <input
      className="p-2 w-16 mr-4 border border-blue-200 hover:border-blue-400
    focus:border-blue-600"
      type_="text"
      value={celcius |> Js.Float.toString}
      onChange=handleCelciusChange
      placeholder={j|°C|j}
    />
    <p className="text-2xl mr-4"> {React.string({j|⇋|j})} </p>
    <input
      className="p-2 w-16 mr-4 border border-blue-200 hover:border-blue-400
    focus:border-blue-600"
      type_="text"
      value={celciusToFarenheit(celcius) |> Js.Float.toString}
      onChange=handleFarenheitChange
      placeholder={j|°F|j}
    />
  </div>;
};
